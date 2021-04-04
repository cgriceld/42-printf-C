<h1>printf</h1>

<strong>My implementation of <code>printf</code> function</strong><br>
42 algorithmic project. The code is written in accordance with The Norm (42 coding style).
This repo uses my own [C library](https://github.com/linpoa/libft) as a submodule.<br>

<h2>How it works:</h2>
<ol>
	<li>Clone this repo, you will have empty <code>libft</code> folder then</li>
	<li>Run <code>git submodule init</code> and <code>git submodule update</code>, after that you will have relevant <code>libft</code> state</li>
	<li>Run <code>make</code> in this repo folder, this will compile <code>libft</code> and <code>printf</code> files to <code>libftprintf.a</code> static library</li>
	<li><code>main.c</code> contains some of my tests, to compile it run script: <code>bash run.sh</code> (you can add/change files you want to compile in <code>run.sh</code></li>
</ol>

***Makefile***
* *`make`* -- compiles `libftprintf.a`.
* *`clean`* -- deletes object files.
* *`fclean`* -- deletes object files and `libftprintf.a`.
* *`re`* -- runs `fclean` and recompiles.

This version supports `c s p d i u x X %` conversions, `- 0` flags, width and precision fields (also passed via an asterisk).<br>
This version **reproduces** undefined behavior which may occur in combinations of the above mentioned flags and specifiers.<br>
Return value is number of written bytes or -1 in case of `write` error.<br>
In case of invalid specifier (e.g. `printf("invalid %10W", 21)`, `W` - invalid) my function writes this invalid specifier as a simple character (so output will be `invalid W`).

<h2>Some theory:</h2>

printf("format", [arguments ...])<br>
"format" = %[flags][width][.precision]type

<ul>

<li><strong>-</strong></li>
	the value is leftaligned within the specified width; by default, it is rightaligned

<li><strong>0</strong></li>
	adds zeros within specified width, by default - spaces<br>
	behavior depends on type (see below)

<li><strong>width</strong></li>
	minimum field width<br>
	can be specified directly in <code>format</code> (nonnegative decimal integer) or through <code>*</code> (int argument)<br>
	negative width is taken as a <code>-</code> flag followed by a positive width (both for <code>format</code> and <code>*</code>)<br>
	if value length > width, width is ignored, otherwise it is padded with spaces on the left (or depending on flags)

<li><strong>precision</strong></li>
	<code>.</code> followed either by nonnegative decimal integer or through <code>*</code> (int argument)<br>
	if only the <code>.</code> is specified, the precision is taken as zero<br>
	behavior depends on type (see below)

<li><strong>d, i</strong></li>
	signed decimal (int)<br>
	if <code>0</code>, leading zeros (if negative, sign before zeros) are used to pad to the width<br>
	if <code>0</code> and <code>-</code> both appear, the <code>0</code> is ignored<br>
	if a precision is specified, the <code>0</code> is ignored<br>
	precision - minimum number of digits to appear (if value < precision, expanded with zeros)<br>
	the result of converting a 0 with 0 precision is no characters

<li><strong>u</strong></li>
	unsigned decimal (unsigned int)<br>
	similar to <strong>d, i</strong>

<li><strong>x, X</strong></li>
	unsigned hexadecimal notation (unsigned int converted to hex)<br>
	x uses lower case (abcdef), X - upper case (ABCDEF)<br>
	similar to <strong>d, i</strong>

<li><strong>c</strong></li>
	int argument converted to unsigned char<br>
	undefined behavior with <code>0</code> and specified precision

<li><strong>s</strong></li>
	pointer to string<br>
	undefined behavior with <code>0</code><br>
	precision specify the maximum number of bytes to be written

<li><strong>p</strong></li>
	pointer of void type<br>
	undefined behavior with <code>0</code> and specified precision

<li><strong>%</strong></li>
	a % character is written<br>
	undefined behavior with <code>0</code> and specified precision

</ul>
