#include "shell.h"
/**
 * _getline- reads an entire line from stream.
 * @lineptr: address of buffer containing text.
 * @n: size of buffer
 *@stream: stream of file
 * Return: Number of bytes read or -1 on error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *buffer;
	size_t index = 0, bytes_read = 0, buf_size = BUFSIZ;
	char *new_buf = NULL, ch;

	if (!lineptr || !n || !stream)
		return (-1);
	buffer = malloc(buf_size);
	while (1)
	{
		if (bytes_read >= (buf_size - 1))
		{
			buf_size += BUFSIZ;
			new_buf = _realloc(buffer, buf_size);
			if (!new_buf)
			{
				free(buffer);
				buffer = NULL;
				return (-1);
			}
			free(buffer);
			buffer = new_buf;
		}
		if ((read(fileno(stream), &ch, 1)) <= 0)
		{
			free(buffer);
			buffer = NULL;
			if (bytes_read > 0)
				return (bytes_read);
			return (-1);
		}
		buffer[index] = ch;
		index++, bytes_read++;
		if (buffer[index - 1] == '\n')
			break;
	}
	buffer[index] = '\0';
	*lineptr = buffer;
	return (bytes_read);
}
