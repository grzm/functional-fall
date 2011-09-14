<?php

function first($ary)
{
  return empty($ary) ? array() : $ary[0];
}

function rest($ary)
{
  return empty($ary) ? array() : array_slice($ary, 1);
}

function cons($el, $ary)
{
  $cons = array($el);
  foreach ($ary as $e)
    $cons []= $e;
  return $cons;
}