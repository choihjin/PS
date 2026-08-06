#include <bits/stdc++.h>
using namespace std;
using Shape = vector<pair<int, int>>;

namespace {

constexpr int DR[4] = {0, 0, 1, -1};
constexpr int DC[4] = {1, -1, 0, 0};

void normalize(Shape& shape) {
    sort(shape.begin(), shape.end());

    const auto [originRow, originCol] = shape.front();
    for (auto& [row, col] : shape) {
        row -= originRow;
        col -= originCol;
    }
}

vector<Shape> extractShapes(const vector<vector<int>>& board, int target) {
    const int size = static_cast<int>(board.size());
    vector<vector<bool>> visited(size, vector<bool>(size));
    vector<Shape> shapes;

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (board[row][col] != target || visited[row][col]) continue;

            queue<pair<int, int>> q;
            Shape shape;

            q.push({row, col});
            visited[row][col] = true;

            while (!q.empty()) {
                const auto [currentRow, currentCol] = q.front();
                q.pop();
                shape.push_back({currentRow, currentCol});

                for (int direction = 0; direction < 4; ++direction) {
                    const int nextRow = currentRow + DR[direction];
                    const int nextCol = currentCol + DC[direction];

                    if (nextRow < 0 || nextRow >= size ||
                        nextCol < 0 || nextCol >= size) {
                        continue;
                    }
                    if (visited[nextRow][nextCol] ||
                        board[nextRow][nextCol] != target) {
                        continue;
                    }

                    q.push({nextRow, nextCol});
                    visited[nextRow][nextCol] = true;
                }
            }

            normalize(shape);
            shapes.push_back(std::move(shape));
        }
    }

    return shapes;
}

void rotateClockwise(Shape& shape) {
    for (auto& [row, col] : shape) {
        const int rotatedRow = col;
        const int rotatedCol = -row;
        row = rotatedRow;
        col = rotatedCol;
    }
    normalize(shape);
}

bool matchesWithRotation(const Shape& blank, Shape piece) {
    for (int rotation = 0; rotation < 4; ++rotation) {
        if (blank == piece) return true;
        rotateClockwise(piece);
    }
    return false;
}

}  // namespace

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    const vector<Shape> blanks = extractShapes(game_board, 0);
    vector<Shape> pieces = extractShapes(table, 1);

    int answer = 0;
    for (const auto& blank : blanks) {
        for (size_t i = 0; i < pieces.size(); ++i) {
            if (!matchesWithRotation(blank, pieces[i])) continue;

            answer += static_cast<int>(blank.size());
            pieces.erase(pieces.begin() + i);
            break;
        }
    }

    return answer;
}
