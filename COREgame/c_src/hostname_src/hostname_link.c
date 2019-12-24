#include "../../c_src_headers/hostname_headers/hostname_link.h"

int is_valid(const char symb)
{
    if (symb == '-')
    {
        printf("detected invalid symbs - \'%c\'\n", symb);
        return ERROR;
    }

    return OK;
}

int is_wrong_format(const char *buf)
{
    if (is_valid(*buf) != OK)
    {
        return ERROR;
    }

    while (*buf)
    {
        if (!((*buf >= 65 && *buf <= 90) || \
              (*buf >= 97 && *buf <= 122) || \
              *buf == '-'))
        {
            printf("detected invalid symbs - \'%c\'\n", *buf);
            return ERROR;
        }

        buf++;
    }

    if (is_valid(*(buf - 1)) != OK)
    {
        return ERROR;
    }

    return OK;
}

int hostname(const char *const buffer, char *const new_hostname)
{
    if (!new_hostname)
    {
        return EMPTY_HOSTNAME;
    }

    if (!buffer)
    {
        if (gethostname(new_hostname, MAX_HOSTNAME_LENGTH))
        {
            printf("cannot get hostname\n");
            return NAME_NOT_GET;
        }
    }
    else if (is_wrong_format(buffer))
    {
        return WRONG_FORMAT;
    }
    else
    {
        if (sethostname(buffer, strlen(buffer)))
        {
            printf("cannot set hostname to %s\n", buffer);
            return NAME_NOT_SET;
        }

        strcpy(new_hostname, buffer);
    }

    return OK;
}
