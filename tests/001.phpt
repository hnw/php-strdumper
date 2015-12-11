--TEST--
Check for str_dump()
--SKIPIF--
<?php if (!extension_loaded("strdumper")) print "skip"; ?>
--FILE--
<?php
$str = "foo";
str_dump($str);
--EXPECTREGEX--
string\(3\) "foo"\(0x[0-9a-f]+\) refcount\(2\) interned
