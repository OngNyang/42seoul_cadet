구조체를 변경.
>outfile1 >>outfile2 >outfile2
이런식으로 올수 있기 때문에, 순서가 필요함.

char **order = {"<", ">>", NULL}
char **redir = {outfile0, .... NULL}


<outfile1

<
outfile1
