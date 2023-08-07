use itertools::*;
use proconio::marker::*;
use proconio::*;
use std::cmp;
use std::collections::*;

fn main() {
    input! {
        n: usize,
        s: [String; n],
    }

    let ans = (0..n).any(|i| {
        (0..n).any(|j| {
            let x = s[i].chars().chain(s[j].chars()).collect::<Vec<_>>();
            let mut y = x.clone();
            y.reverse();
            (i != j) && (x == y)
        })
    });

    println!("{}", if ans { "Yes" } else { "No" });
}
