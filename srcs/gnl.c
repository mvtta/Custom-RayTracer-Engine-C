#include "gnl.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int has_line(char *str)
{
    int i = 0;
    while (str && str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (NO_LINE);
}

char *make_line(char *archive)
{
    int i = 0;
    char *line = NULL;
    line = malloc(1000);

    while (archive[i] != '\n')
    {
        line[i] = archive[i];
        i++;
    }
    line[i] = '\n';
    line[i + 1] = 0;
/*     write(1, "line\n", 5);
    write(1, line, i + 1); */
    return (line);
}

char *make_less(char *archive, int new_start)
{
    int i = 0;
    char *new = malloc(ft_strlen(archive) - new_start + 1);

    while (archive[new_start])
    {
        new[i] = archive[new_start];
        i++;
        new_start++;
    }
    new[i] = 0;
    //free(archive);
    return (new);
}

char *ft_join(char *buf, char *archive)
{
    int i = 0;
    int k = 0;
    char *new = malloc(ft_strlen(buf) + ft_strlen(archive) + 1);

    /* printf("buf in join: %s\n", buf);
    printf("archive before join: %s\n", archive); */
    while (archive[i])
    {
        new[i] = archive[i];
        i++;
    }
    while (buf[k])
    {
        new[i] = buf[k];
        i++;
        k++;
    }
    new[i] = 0;
    //free(archive);
   // printf("archive after join: %s\n", new);
    return (new);
}

char *get_next_line(int fd)
{
    char *line;
    static char *archive;
    static int end;
    char buf[BUFFER_SIZE + 1] =  "";
    int r;

    if (end == 1)
        return (NULL);
    if (!archive)
        archive = malloc(BUFFER_SIZE + 1);      
    if (has_line(archive))
    {
        line = make_line(archive);
        archive = make_less(archive, ft_strlen(line));
        return (line);
    }
    while ((r = read(fd, buf, BUFFER_SIZE)))
    {
        archive = ft_join(buf, archive);
        if (has_line(archive))
        {
            line = make_line(archive);
            archive = make_less(archive, ft_strlen(line));
            return (line);
        }
    }
    end += 1;
    return (NULL);
}