use std::io::{self, Read};

use std::io::Write;

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();

    let i: Vec<u64> = buf
        .split_ascii_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    buf.clear();

    let result: u64;

    if i[0] == i[1] && i[0] == i[2] {
        result = 10000 + i[0] * 1000;
    } else if i[0] == i[1] || i[0] == i[2] {
        result = 1000 + i[0] * 100;
    } else if i[1] == i[2] {
        result = 1000 + i[2] * 100;
    } else {
        result = *i.iter().max().unwrap() * 100;
    }

    write!(out, "{}", result).unwrap();
}
