#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int arc, char **arv)
{
	int i, j, x, y;
	FILE *source, *target;
	char *buf = NULL, tmp[1024], tmp2[1024];
	size_t n;

	if (arc < 2)
	{
		fprintf(stderr, "usage : tsp <filename>\n");
		return (1);
	}
	for (i = 1; i < arc; i++)
	{
		strcpy(tmp, arv[i]);
		strcat(tmp, "___");
		source = fopen(arv[i], "r");
		if (source == NULL)
		{
			fprintf(stderr, "couldn't open file \"%s\"\n", arv[i]);
			continue;
		}
		target = fopen(tmp, "a");
		if (target == NULL)
		{
			fprintf(stderr, "unxpected error\n");
			continue;
		}
		while (getline(&buf, &n, source) != -1)
		{
			j = 0;
			x = 0;
			while (buf[j] != '\0')
			{
				if (buf[j] == '\t')
				{
					for (y = 0; y < 4; y++)
					{
						tmp2[x] = ' ';
						x++;
					}
					j++;
				}
				else
				{
					tmp2[x] = buf[j];
					j++;
					x++;
				}
			}
			tmp2[x] = '\0';
			fputs(tmp2, target);
		}
		free(buf);
		buf = NULL;
		fclose(source);
		if (rename(tmp, arv[i]) == -1)
		{
			remove(tmp);
			fprintf(stderr, "make sure %s have execution permissons"
			" or is not a directory\n", arv[i]);
			continue;
		}
		fclose(target);
	}
	return (0);
}