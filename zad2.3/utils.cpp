void string_copy(char* t, char* str)
{
	for (char* d = t, *s = str; *d++ = *s++;)
	*t = *d;
}

int len(const char *s)
{
	int len = 0;
	while (*(s++))
		len++;
	return len;

}
	
int compare(const char* s, const char* t)
{
        int result, i = 0;
        while(true){
            if ((result = s[i] - t[i]) !=0 || !s[i]) break;
            i++;
        }
        if (!result) return 0;
       else return (result > 0) ? (1) : (-1);
}