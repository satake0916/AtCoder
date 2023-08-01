use proconio::*;
use std::collections::*;
use std::cmp::*;

fn main() {
    input!{
        n: usize,
        p: usize,
        q: usize,
        d: [usize; n]
    }
    println!("{}", min(p, q + d.iter().min().unwrap()))
}
