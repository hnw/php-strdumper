--TEST--
Check for is_interned()
--SKIPIF--
<?php if (!extension_loaded("strdumper")) print "skip"; ?>
--FILE--
<?php
$str = "foo";
var_dump(is_interned($str));
--EXPECT--
bool(true)
