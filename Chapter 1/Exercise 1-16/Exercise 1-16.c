#include <stdio.h>
#define MAXLINE 10 /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len;					/* current line length */
	int leno;                   /* overflowed line length */
	int max;					/* maximum length seen so far */
	char line[MAXLINE];			/* current input line */
	char lineo[MAXLINE];        /* overflowed input line */
	char longest[MAXLINE];		/* longest line saved here */

	max = 0;
	len = getline(line, MAXLINE);
	while ((leno = len) > 0) {
		if (len == MAXLINE-1 && line[MAXLINE-2] != '\n')
			while ((leno = getline(lineo, MAXLINE)) > 0 && (len = len + leno) && lineo[leno-1] != '\n')
                ;
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		if ((len = leno) > 0)
            len = getline(line, MAXLINE);
	}
	if (max > 0) /* there was a line */
		printf("%s", longest);
		printf("\nMax length = %d", max); /* for checking */
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
