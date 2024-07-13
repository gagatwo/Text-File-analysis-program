Text file 분석 프로그램

1. wordcounting.c
텍스트 파일의 newline, word, character(줄바꿈까지 character에 포함) 수를 출력하는 프로그램
단, 텍스트에서 주석 처리된 부분은 제외하고 counting
주석의 종류 : /* */, //

Ex) 입력된 텍스트 -> 주석이 제외된 텍스트 -> 결과물
abc/*def*/ghi -> abc ghi -> newline: 0, word: 2, character: 7

abc/*def/*ghi*/jkl*/mno -> abcsjkl*/mno -> newline: 0, word: 2, character: 12

abc//def/*ghi  -> abc  -> newline: 1, word: 2, character: 9
*/jkl             */jkl

구현 방식 : 텍스트 파일의 한 글자씩 읽으며 일반적인 글자인지, 공백인지, /인지 등의 case를 나누어 조건문으로 구현


2. wordcounting_dfa.pdf
wordcountig 알고리즘을 가시화한 DFA 자료


3. sgrep.c
텍스트 파일에서 사용자가 검색한 단어가 포함된 줄을 출력하는 프로그램
단, 검색하는 단어에 *이 포함될 때 해당 *의 위치에는 아무 문자열이나 포함되어도 상관 없도록 알고리즘 설계

Ex)
he*llo 검색 -> heillo, heasdfgghjllo 등 의 단어가 포함된 줄을 출력함
*p*le* 검색 -> apple, people 등의 단어가 포함된 줄을 출력함

구현 방식: 텍스트 파일의 한 줄씩 buffer로 저장하고, 포인터를 이용해 buffer와 검색하는 단어의 한 글자씩 pointing하며 두 글자가 동일한지 아니면 *로 인해서 아무 글자나 상관없는지 비교를 반복하여 구현
 
 
