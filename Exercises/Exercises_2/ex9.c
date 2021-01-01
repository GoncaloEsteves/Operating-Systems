ssize_t read_full_line(int fd, char **buffer){
	int buf_size = BUFFER_SIZE;
	
	*buffer = malloc(sizeof(char)*buf_size);

	ssize_t butes_read = 0;
	ssize_t res = 0;

	while ((res = readln(fd, *buffer+bytes_read, BUFFER_SIZE)) > 0){
		bytes_read += res;

		if(res == BUFFER_SIZE && *buffer[bytes_read-1] != '\n'){
			buf_size += BUFFER_SIZE;
			*buffer = realloc(*buffer, buf_size);
		}
		else{
			
		}
	}
}