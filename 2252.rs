use std::{collections::VecDeque, io};

use std::io::Write;

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("Fail");

    let first: Vec<i32> = buf
        .split_ascii_whitespace()
        .map(|x| x.parse().expect("Fail"))
        .collect();

    buf.clear();

    let n = first[0];
    let m = first[1];

    let mut i = 0;

    let mut indegree = vec![0; (n + 1) as usize];
    let mut trasition: Vec<Vec<i32>> = vec![vec![]; (n + 1) as usize];

    while i < m {
        io::stdin().read_line(&mut buf).expect("Fail");

        let second: Vec<i32> = buf
            .split_ascii_whitespace()
            .map(|x| x.parse().expect("Fail"))
            .collect();

        buf.clear();

        let a = second[0];
        let b = second[1];

        indegree[b as usize] += 1;

        trasition[a as usize].push(b);

        i += 1;
    }

    let mut queue: VecDeque<i32> = VecDeque::new();
    let mut i = 1;

    while i <= n {
        if indegree[i as usize] == 0 {
            queue.push_back(i)
        }
        i += 1;
    }

    while !queue.is_empty() {
        let e = queue.pop_front().unwrap();

        write!(out, "{} ", e).unwrap();

        for x in &trasition[e as usize] {
            indegree[*x as usize] -= 1;

            if indegree[*x as usize] == 0 {
                queue.push_back(*x);
            }
        }
    }
}
