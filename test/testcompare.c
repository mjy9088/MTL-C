#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("usage: %s file1 file2\n", argv[0]);
		return -2;
	}
	FILE *f1 = fopen(argv[1], "rb");
	if(!f1)
	{
		printf("Failed to open file: %s\n", argv[1]);
		return -3;
	}
	FILE *f2 = fopen(argv[1], "rb");
	if(!f2)
	{
		fclose(f1);
		printf("Failed to open file: %s\n", argv[2]);
		return -4;
	}
	char buf1[1024], buf2[1024];
	int read1, read2, i;
	while(!feof(f1) && !feof(f2))
	{
		read1 = fread(buf1, sizeof(char), 1024, f1);
		if(ferror(f1))
		{
			fclose(f1);
			fclose(f2);
			printf("Error reading file: %s\n", argv[1]);
			return -5;
		}
		read2 = fread(buf2, sizeof(char), 1024, f2);
		if(ferror(f2))
		{
			fclose(f1);
			fclose(f2);
			printf("Error reading file: %s\n", argv[2]);
			return -5;
		}
		if(read1 != read2)
		{
			fclose(f1);
			fclose(f2);
			return 2;
		}
		for(i = 0; i < read1; i++)
		{
			if(buf1[i] != buf2[i])
			{
				fclose(f1);
				fclose(f2);
				return 1;
			}
		}
	}
	if(!feof(f1) != !feof(f2))
	{
		fclose(f1);
		fclose(f2);
		return 2;
	}
	if(ferror(f1))
	{
		fclose(f1);
		fclose(f2);
		printf("Error reading file: %s\n", argv[1]);
		return -6;
	}
	if(ferror(f2))
	{
		fclose(f1);
		fclose(f2);
		printf("Error reading file: %s\n", argv[2]);
		return -6;
	}
    return 0;
}

