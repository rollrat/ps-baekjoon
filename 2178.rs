use std::collections::VecDeque;
use std::io::{self, stdout};

use std::io::Write;

pub fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("Fail");
    let n: Vec<i32> = buf
        .split_whitespace()
        .map(|x| x.parse().expect("Fail"))
        .collect();
    // for i in &n {
    //     writeln!(out, "{}", i).unwrap();
    // }
    buf.clear();

    let mut i = 0;
    let mut matrix: Vec<Vec<i32>> = Vec::new();

    while i < n[0] {
        io::stdin().read_line(&mut buf).expect("Fail");
        matrix.push(
            buf.trim()
                .chars()
                .map(|x| x.to_digit(10).expect("Fail") as i32)
                .collect(),
        );
        buf.clear();
        i += 1;
    }

    // for xx in matrix {
    //     for yy in xx {
    //         write!(out, "{}", yy).unwrap();
    //     }
    //     writeln!(out, "").unwrap();
    // }

    fn check_bound(n: &Vec<i32>, x: (i32, i32)) -> bool {
        n[0] > x.0 && n[1] > x.1 && x.0 >= 0 && x.1 >= 0
    }

    let mut deq = VecDeque::from([(0, 0, 0)]);

    while !deq.is_empty() {
        let d = deq.pop_front().unwrap();

        matrix[d.0 as usize][d.1 as usize] = 0;

        if d.0 == n[0] - 1 && d.1 == n[1] - 1 {
            write!(out, "{}", d.2 + 1).unwrap();
            break;
        }

        if check_bound(&n, (d.0 + 1, d.1)) && matrix[(d.0 + 1) as usize][d.1 as usize] == 1 {
            matrix[(d.0 + 1) as usize][d.1 as usize] = 0;
            deq.push_back((d.0 + 1, d.1, d.2 + 1));
        }
        if check_bound(&n, (d.0 - 1, d.1)) && matrix[(d.0 - 1) as usize][d.1 as usize] == 1 {
            matrix[(d.0 - 1) as usize][d.1 as usize] = 0;
            deq.push_back((d.0 - 1, d.1, d.2 + 1));
        }
        if check_bound(&n, (d.0, d.1 + 1)) && matrix[(d.0) as usize][(d.1 + 1) as usize] == 1 {
            matrix[d.0 as usize][(d.1 + 1) as usize] = 0;
            deq.push_back((d.0, d.1 + 1, d.2 + 1));
        }
        if check_bound(&n, (d.0, d.1 - 1)) && matrix[(d.0) as usize][(d.1 - 1) as usize] == 1 {
            matrix[d.0 as usize][(d.1 - 1) as usize] = 0;
            deq.push_back((d.0, d.1 - 1, d.2 + 1));
        }
    }
}
