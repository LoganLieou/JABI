open Base
open Stdio

let cleanup (s: String.t): String.t = 
  String.filter s ~f:(String.mem "+-.,[]<>")

let () =
  let contents = In_channel.read_all (Caml.Sys.argv.(1)) in
  print_endline contents;
  let rem = " kkk ggg fff vvv [] + , ---- <<<<" in
  print_endline (cleanup rem)
