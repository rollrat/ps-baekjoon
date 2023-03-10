use std::io;

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

    write!(out, "{}", i[0] + i[1] + i[2]).unwrap();
}
