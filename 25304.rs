use std::fmt;
use std::io::{self, Read};

use std::io::Write;
use std::str::FromStr;

fn read_int<T>(buf: &mut String) -> T
where
    T: FromStr,
    <T as FromStr>::Err: fmt::Debug,
{
    buf.clear();
    io::stdin().read_line(buf).unwrap();
    buf.trim().parse().unwrap()
}

fn read_ints<T>(buf: &mut String) -> Vec<T>
where
    T: FromStr,
    <T as FromStr>::Err: fmt::Debug,
{
    buf.clear();
    io::stdin().read_line(buf).unwrap();
    buf.split_ascii_whitespace()
        .map(|x| x.parse().unwrap())
        .collect()
}

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();

    let x: u64 = read_int(&mut buf);
    let n: u64 = read_int(&mut buf);

    let mut acc: u64 = 0;

    for _ in 0..n {
        let ab: Vec<u64> = read_ints(&mut buf);

        acc += ab[0] * ab[1];
    }

    write!(out, "{}", if x == acc { "Yes" } else { "No" }).unwrap();
}
