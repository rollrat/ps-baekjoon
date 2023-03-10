use std::io::{self, Read};

use std::io::Write;

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("Fail");

    let i: Vec<u64> = buf
        .split_ascii_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    buf.clear();

    io::stdin().read_line(&mut buf).expect("Fail");

    let s: u64 = buf.trim().parse().unwrap();

    let d = (i[1] + s) / 60;
    let h = (i[0] + d) % 24;

    write!(out, "{} {}", h, (i[1] + s) % 60).unwrap();
}
