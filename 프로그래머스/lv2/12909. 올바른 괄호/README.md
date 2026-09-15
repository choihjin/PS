# [level 2] 올바른 괄호 - 12909

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12909)

### 성능 요약

메모리: 5.02 MB, 시간: 0.41 ms

### 구분

코딩테스트 연습 > 스택／큐

### 채점결과

<br/>정확성: 69.5<br/>효율성: 30.5<br/>합계: 100.0 / 100.0

### 문제 설명

<div class="tab-pane fade active show" id="tour2">
        <div class="guide-section-description">
          <h6 class="guide-section-title">
            문제 설명
          </h6>
          <div class="markdown solarized-dark"><p>괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 예를 들어</p>

<ul>
<li>"()()" 또는 "(())()" 는 올바른 괄호입니다.</li>
<li>")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.</li>
</ul>

<p>'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.</p>

<h5>제한사항</h5>

<ul>
<li>문자열 s의 길이 : 100,000 이하의 자연수</li>
<li>문자열 s는 '(' 또는 ')' 로만 이루어져 있습니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>s</th>
<th>answer</th>
</tr>
</thead>
        <tbody><tr>
<td>"()()"</td>
<td>true</td>
</tr>
<tr>
<td>"(())()"</td>
<td>true</td>
</tr>
<tr>
<td>")()("</td>
<td>false</td>
</tr>
<tr>
<td>"(()("</td>
<td>false</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1,2,3,4<br>
문제의 예시와 같습니다.</p>
</div>
        </div>
      </div>


        <div class="submission-history-list-section tab-pane fade" id="submissionHistory">
          <div class="submission-history-wrapper">


  <div data-challengeable-submission-history-component="submission-history" data-user-id="442478" data-lesson-id="12909" data-current-theme="dark" data-webapp="true" style="width: 100%; height: 100%;"></div>
  <script src="https://hera-client.grepp.co/269c0e1cc4ea037ef673.js" defer="defer"></script>
</div>

        </div>

> 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
