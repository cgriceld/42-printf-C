My own implementation of `printf` function. It also uses function from my own C library (libft).

printf ("format", [arguments ...])\
"format" = %[flags][width][.precision]type

This version supports `c s p d i u x X %` conversions, `- 0` flags, width and precision fields.\
This version doesn't reproduce undefined behavior.\
Returns number of written bytes or -1 in following cases:\
- no conversion specifier at all or a wrong one\
- negative precision in `format`

- `-`\
	the value is leftaligned within the specified width; by default, it is rightaligned\
- `0`\
	adds zeros within specified width, by default - spaces\
	behavior depends on type (see below)

- width\
	minimum field width\
	can be specified directly in `format` (nonnegative decimal integer) or through `*` (int argument)\
	negative width is taken as a `-` flag followed by a positive width (both for `format` and `*`)\
	if value length > width, width is ignored, otherwise it is padded with spaces on the left (or depending on flags)

- precision\
	`.`followed either by nonnegative decimal integer or through `*` (int argument)\
	if negative precision through `*` - ignored, if negative precision directly in `format` - won't compile\
	with `-Wall -Wextra -Werror`\
	if only the `.` is specified, the precision is taken as zero\
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