struct file_operations fops =
{
	open: dev_open,
	write: dev_write,
	read: dev_read,
	llseek: dev_lseek,
	release: dev_release
};
