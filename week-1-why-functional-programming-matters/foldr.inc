<?php
require_once('list.inc');
/*
  higher-order functions
  lazy evaluation

  listof * ::= Nil | Cons * (listof *)

  [] means Nil
  [1] means Cons 1 Nil
  [1,2,3] means Cons 1 (Cons 2 (Cons 3 Nil))

  sum Nil = 0
  sum (Cons n list) = n + sum list

  sum = foldr (+) 0
*/


function foldr($f, $a)
{
  $fn = function($lst) use ($f, $a, &$fn)
    {
      if (empty($lst))
        return $a;

      return $f(first($lst), $fn(rest($lst)));
    };
  return $fn;
}


/*

  (foldr f x) Nil = x
  (foldr f x) (Cons a l) = f a ((foldr f x) l)

*/


