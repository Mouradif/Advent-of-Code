const std = @import("std");
const BUF_SIZE = 1024;

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();

    var floor: i64 = 0;
    var current_index: usize = 0;
    var first_basement_index: usize = 0;
    var buf: [BUF_SIZE]u8 = undefined;
    while (true) {
        const read_bytes = try stdin.read(&buf);
        if (read_bytes == 0) {
            break;
        }
        for (buf[0..read_bytes]) |c| {
            if (c == '(') floor += 1;
            if (c == ')') floor -= 1;
            current_index += 1;
            if (floor == -1 and first_basement_index == 0) {
                first_basement_index = current_index;
            }
        }
    }
    try stdout.print("{}\n{}\n", .{ floor, first_basement_index });
}
