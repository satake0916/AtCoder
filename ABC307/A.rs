use proconio::*;
use std::collections::*;
use std::cmp::*;

fn main() {
    input!{
        n: usize,
        a: [usize; 7 * n]
    }
    for i in 0..n {
        let mut count = 0;
        for j in 0..7 {
            count += a[7 * i + j];
        }
        print!{"{} ", count}
    }
}
