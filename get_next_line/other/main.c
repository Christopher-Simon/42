#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "../get_next_line.h"
#include "../get_next_line_bonus.h"

int main(void)
{
	int fd;
	int ret;
	char *line;

	/*    
	fd1 = open("c", O_RDONLY);
	fd2 = open("Test", O_RDONLY);
	fd3 = open("bible.txt", O_RDONLY);*/

	//fd = open("./gnlTester/files/42_no_nl", O_RDONLY);
	fd = open("Test", O_RDONLY);
	if (fd == -1)
	{
		printf("non");
		return (0);
	}
	int	i = 0;
#include "get_next_line_bonus.h"
	while ((line = get_next_line(fd)) && i < 25)
    {
		printf("%s", line);
		printf("1");
		free(line);
		i++;
	}
    /*
    while (line)
    {
    	printf("%s", line);
	    free(line);
        line = get_next_line(fd1);
		printf("%s", line);
	    free(line);
        line = get_next_line(fd2);
		printf("%s", line);
	    free(line);
        line = get_next_line(fd3);
    }
    free (line);*/
    
    if (close(fd) == -1)
    {
        printf("\nclose echec");
        return (0);
    }
    printf("\nclose success");
    return (0);
}