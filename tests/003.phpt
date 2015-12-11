--TEST--
Check for interned_strings()
--SKIPIF--
<?php if (!extension_loaded("strdumper")) print "skip"; ?>
--FILE--
<?php
$interned = interned_strings();
var_dump(is_array($interned));
var_dump(sizeof($interned));
var_dump(in_array("var_dump", $interned));
--EXPECTREGEX--
bool\(true\)
int\([0-9]+\)
bool\(true\)
