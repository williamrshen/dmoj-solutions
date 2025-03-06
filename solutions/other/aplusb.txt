#[macro_use] extern crate dmoj;
use std::io;

fn main() {
    let n = scan!(u32);
    for i in 0..n {
        let (a,b) = scan!(i32, i32);
        println!("{}", a+b);
    }
}