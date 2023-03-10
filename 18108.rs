use std::io;

use std::io::Write;

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("Fail");

    let y: i32 = buf.trim().parse().expect("Fail");

    buf.clear();

    write!(out, "{}", y - 2541 + 1998).unwrap();
}
