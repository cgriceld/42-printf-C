My implementation of `printf` function. This repo uses my own C library ([libft](https://github.com/linpoa/libft)) as a submodule.

How it works:<br>
<ol>
	<li>Clone this repo, you will have empty `libft` folder then</li>
	<li>Run `git submodule init` and `git submodule update`, after that you will have relevant `libft` state</li>
	<li>Run `make` in this repo folder, this will compile `libft` and `printf` files to `libftprintf.a` static library</li>
	<li>`main.c` contains some of my tests, to compile it run script: `bash run.sh` (you can add/change files you whant to compile in `run.sh`</li>
</ol>

This version supports `c s p d i u x X %` conversions, `- 0` flags, width and precision fields (also passed via an asterisk).<br>
This version **reproduces** undefined behavior which may occur in combinations of the above mentioned flags and specifiers.<br>
Return value is number of written bytes or -1 in case of `write` error.<br>
In case of invalid specifier (e.g. `printf("invalid "%10W", 21)`, `W` - invalid) my function writes this invalid specifier as a simple character (so output will be `invalid W`).

Some theory:<br>

printf ("format", [arguments ...])<br>
"format" = %[flags][width][.precision]type

<ul>
<li>`-`</li><br>
	the value is leftaligned within the specified width; by default, it is rightaligned<br>
<li>`0`</li><br>
	adds zeros within specified width, by default - spaces<br>
	behavior depends on type (see below)
</ul>

- width<br>
	minimum field width<br>
	can be specified directly in `format` (nonnegative decimal integer) or through `*` (int argument)<br>
	negative width is taken as a `-` flag followed by a positive width (both for `format` and `*`)<br>
	if value length > width, width is ignored, otherwise it is padded with spaces on the left (or depending on flags)

- precision<br>
	`.`followed either by nonnegative decimal integer or through `*` (int argument)<br>
	if negative precision through `*` - ignored, if negative precision directly in `format` - won't compile<br>
	with `-Wall -Wextra -Werror`<br>
	if only the `.` is specified, the precision is taken as zero<br>
	behavior depends on type (see below)

Types:

- `d, i`\
	signed decimal (int)\
	if `0`, leading zeros (if negative, sign before zeros) are used to pad to the width\
	if `0` and `-` both appear, the `0` is ignored\
	if a precision is specified, the `0` is ignored\
	precision - minimum number of digits to appear (if value < precision, expanded with zeros)\
	the result of converting a 0 with 0 precision is no characters

- `u`\
	unsigned decimal (unsigned int)\
	similar to `d, i`

- `x, X`\
	unsigned hexadecimal notation (unsigned int converted to hex)\
	x uses lower case (abcdef), X - upper case (ABCDEF)\
	similar to `d, i`

- `c`\
	int argument converted to unsigned char\
	undefined behavior with `0` and specified precision

- `s`\
	pointer to string\
	undefined behavior with `0`\
	precision specify the maximum number of bytes to be written

- `p`\
	pointer of void type\
	undefined behavior with `0` and specified precision

- `%`\
	a % character is written\
	undefined behavior with `0` and specified precision