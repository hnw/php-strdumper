--TEST--
Check for is_interned()
--SKIPIF--
<?php
    if (!extension_loaded("strdumper")) print "skip";
    if (version_compare(PHP_VERSION, '5.2.7') >= 0 && PHP_ZTS) print "skip";
--FILE--
<?php
$str = "foo";
var_dump(is_interned($str));
--EXPECT--
bool(true)
