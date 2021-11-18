#include "gnl.h"

static int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int has_line(char *str)
{
    int i = 0;
    while (str[i])
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
    line = malloc(i + 1);
    int l;
    l = has_line(archive) + 1;

    while (i < l)
    {
        line[i] = archive[i];
        i++;
    }
    line[i] = 0;
    return (line);
}

char *make_less(char *archive, char *line)
{
    int i = 0;
    int total_size;
    int line_len = ft_strlen(line);

    total_size = ft_strlen(archive) - line_len;
    char *new = malloc(total_size + 1);
    while (archive[line_len])
    {
        new[i] = archive[line_len];
        i++;
        line_len++;
    }
    new[i] = 0;
    free(archive);
    return (new);
}

char *ft_join(char *buf, char *archive)
{
    int i = 0;
    int k = 0;
    char *new = malloc(ft_strlen(buf) + ft_strlen(archive) + 1);

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
    free(archive);
    return (new);
}

char *get_next_line(int fd)
{
    char *line = NULL;
    static char *archive;
    static int end;
    if (end == 1)
        return (NULL);
    char buf[BUFFER_SIZE + 1];
    int r;
    if (!archive)
        archive = malloc(0);
    if (has_line(archive))
    {
        line = make_line(archive);
        archive = make_less(archive, line);
        return (line);
    }
    while ((r = read(fd, buf, BUFFER_SIZE)))
    {
        archive = ft_join(buf, archive);
        if (has_line(archive))
        {
            line = make_line(archive);
            archive = make_less(archive, line);
            return (line);
        }
    }
    line = ft_join("", archive);
    archive = NULL;
    end += 1;
    return (line);
}