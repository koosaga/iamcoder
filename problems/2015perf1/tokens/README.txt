[학생 제공]
* grader.cpp -> 학생들에게 제공되는 Sample Grader
* tokens.cpp -> 학생들이 작성하게 될 cpp 파일
* tokens.h -> 헤더

[선생님 전용]
* koistudy.cpp -> 채점용 프로그램. 
* tokens_sol.cpp -> 모범 풀이

[채점 방식]
학생의 cpp 파일이 tokens.cpp이며, tokens.h와 koistudy.cpp와 tokens.cpp가 같은 폴더에 있을 때

	g++ -o tokens tokens.cpp koistudy.cpp

명령어로 빌드할 수 있습니다.

tokens 프로그램은 표준 입력으로 45개의 입력 파일을 입력 받습니다. 출력 파일은 불필요합니다.

입력된 파일을 토대로 tokens 프로그램은 표준 출력에 Accepted나 Wrong Answer를 반환합니다.