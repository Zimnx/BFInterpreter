#include <cstdio>
#include <cstdlib>

size_t readfile(char* filename, char* buffer,size_t size)
{
	FILE *file;
	size_t fsize;

	file = fopen ( filename , "r" );
	if (file==NULL) 
	{
		puts ("error: cannot open file"); return 0;
	}
	fseek (file , 0 , SEEK_END);
	fsize = ftell (file);
	rewind (file);
	if(fsize > size)
	{
		puts("error: file too large"); return 0;
	}
	size_t result = fread (buffer,1,fsize,file);
	fclose(file);
	return result;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		puts("usage: bfi <FileName>");
		return 1;
	}
	char *filename = argv[1];
	char *filebuffer = new char[64*1024];
	size_t fileSize = readfile(filename,filebuffer,64*1024);
	if(fileSize == 0)
	{
		return 2;
	}
	static int memory[30000];
	int memptr = 0;
	for(size_t i = 0 ; i < fileSize; ++i)
	{
		switch(filebuffer[i])
		{
		case '<':
			if(memptr == 0)
			{
				memptr = 29999;
			}
			else
			{
				memptr--;
			}
			break;
		case '>':
			if(memptr == 29999)
			{
				memptr = 0;
			}
			else
			{
				memptr++;
			}
			break;
		case '+':
			memory[memptr]++;
			break;
		case '-':
			memory[memptr]--;
			break;
		case '.':
			putchar(memory[memptr]);
			break;
		case ',':
			memory[memptr] = getchar();
			break;
		case '[':
			if(memory[memptr] == 0)
			{
				int depth = 1;
				i++;
				while(depth != 0)
				{
					if(filebuffer[i] == '[')
						depth++;
					if(filebuffer[i] == ']')
						depth--;
					i++;
				}
			}
			break;
		case ']':
			int depth = 1;
			i--;
			while(depth != 0)
			{
				if(filebuffer[i] == '[')
					depth--;
				if(filebuffer[i] == ']')
					depth++;
				i--;
			}
			break;
		}
	}

	return 0;
}