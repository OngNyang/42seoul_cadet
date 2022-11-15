int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' <= c <= 'Z'))
		return (1024);
	else
		return (0);
}

//return value is 
//quoted from man isalpha
//"Return Value : The values returned are nonzero if the character c falls into the tested class, and a zero value if not."