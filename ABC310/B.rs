use proconio::*;
use std::collections::*;
use std::cmp::*;
use itertools::*;

fn main() {
    input!{
        n: usize,
        m: usize,
    }
    let mut a = vec![];
    for _ in 0..n {
        input!{
            p: usize,
            c: usize,
            f: [usize; c],
        }
        a.push((p, f));
    }

    let mut isOK = false;

    for x in a.iter(){
        for y in a.iter(){
            let mut temp = true;
            let (px, fx) = (x.0, &x.1);
            let (py, fy) = (y.0, &y.1);
            temp &= px <= py;
            temp &= fy.iter().all(|x| fx.contains(x));
            temp &= px != py || fx.len() != fy.len();

            isOK |= temp;
        }
    }

    println!("{}", if isOK {"Yes"} else {"No"});
}
