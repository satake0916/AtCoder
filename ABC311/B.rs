use proconio::*;
use proconio::marker::*;
use std::cmp;
use std::collections::*;
use itertools::*;

fn main() {
    input! {
        n: usize,
        d: usize,
        s: [Bytes; n],
    }
    let mut ans: usize = 0;
    for i in 0..d {
        let mut ok = true;
        for r in i..d {
            ok &= s.iter().all(|s| s[r] == b'o');
            if ok {
                ans = ans.max(r - i + 1);
            }
        }
    }

    println!("{}", ans);
}
