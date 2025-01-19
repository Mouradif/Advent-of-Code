const std = @import("std");
const BUF_SIZE = 1024;

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();

    var floor: i64 = 0;
    var buf: [BUF_SIZE]u8 = undefined;
    while (true) {
        const line = try stdin.read(&buf);
        if (line == 0) {
            break;
        }
        for (buf[0..line]) |c| {
            if (c == '(') floor += 1;
            if (c == ')') floor -= 1;
        }
    }
    try stdout.print("{}\n", .{floor});
}
