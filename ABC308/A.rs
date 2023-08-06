use proconio::*;
use std::collections::*;
use std::cmp::*;

fn main() {
    let n = 8;
    input!{
        s: [i32; n]        
    }
    let mut pre = 0;
    let mut f = true;
    for i in s {
        if i < pre {f = false;}
        if i < 100 || i > 675 {f = false;}
        if i % 25 != 0 {f = false;}
        pre = i;
    }
    println!("{}", if f {"Yes"} else {"No"});
}
