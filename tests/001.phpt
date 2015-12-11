--TEST--
Check for str_dump()
--SKIPIF--
<?php if (!extension_loaded("strdumper")) print "skip"; ?>
--FILE--
<?php
$foo = "interned";
$bar = $foo;
str_dump($foo);
str_dump($bar);
--EXPECTREGEX--
(string\(8\) "interned"\(0x[0-9a-f]+\) refcount\(\d+\) interned)\n\1
