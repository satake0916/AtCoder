use proconio::*;
use proconio::marker::*;
use std::cmp;
use std::collections::*;
use itertools::*;

fn main() {
    input! {
        n: usize,
        m: usize,
        c: [String; n],
        d: [String; m],
        p: [usize; m+1],
    }

    let mp = d.iter().zip(p.iter().skip(1)).map(|(x, y)| (x.clone(), *y)).collect::<HashMap<String, usize>>();
    let ans: usize = c.iter().map(|x| mp.get(x).unwrap_or(&p[0])).sum();

    println!("{}", ans);
}
