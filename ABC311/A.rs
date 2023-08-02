use proconio::*;
use std::collections::HashSet;

fn main() {
    input! {
    	   n: usize,
        s: marker::Chars
    }
    let mut st = HashSet::new();    
    for i in 0..n {
    	let c = s[i];
    	st.insert(c);
	if st.len() == 3 {
	   println!{"{}", i + 1};
	   return;
	}
	}
}
