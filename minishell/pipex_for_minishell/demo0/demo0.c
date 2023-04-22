#include "demo0.h"

/*
- 구조체에 전부 파싱 하고 시작.
- 파이프 단위로 끊어서 생각해야함
- 각 파이프마다 리디렉트 키워드 확인해야함.
*/

// < infile < infile0 cat | grep 1 | < infile2 grep a | < infile3 wc -l > outfile > outfile2
/*
1번 process
	<	:	infile, infile0
	>	:	x
	<<	:	x
	>>	:	x
	cmd	:	cat
2번 process
	<	:	x
	>	:	x
	<<	:	x
	>>	:	x
	cmd	:	grep 1
3번 process
	<	:	infile2
	>	:	x
	<<	:	x
	>>	:	x
	cmd	:	grep a
4번 process
	<	:	infile3
	>	:	outfile, outfile2
	<<	:	x
	>>	:	x
	cmd	:	wc -l

리디렉션 키워드는 파싱 어려울거 같은데... 그냥 while문(open()) 돌려서 할까?
만약 cmd 없으면 그냥 와일문 종료 하면 될듯 open만 하고 꺼지게.
*/

/*
파싱 어케할까.
연결리스트로?
인덱스만 넣을까?
*/

/*
파싱 수두코드

필요한 함수
	: char**의 일부를 떼어내서 새로 만들기, 
	  deque 관련 함수 만들기.

while ()
{
	if (<,>,>>,<< 만나면)
		구조체의 해당하는 char**에 넣기
	else
		<,>,>>,<< 또는 NULL 만날때까지 구조체의 char **cmd에 넣기

}
*/




/*
수두코드
while ()
{
	if (<,>,>>,<< 만나면)
		그에 맞게 입출력 리디렉션
}
while ()
{
	if (<,>,>>,<< 만나면)
		인덱스 2개증가
	else
		cmd 실행
}

*/
