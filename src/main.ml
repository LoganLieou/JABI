open Base
open Stdio

let cleanup (s: String.t): String.t = 
  String.filter s ~f:(String.mem "+-.,[]<>")

let get_bracemap (s: String.t) =
  let bracemap = Hashtbl.create (module Int) in
  let bracestack = Stack.create () in
  for i = 0 to String.length s do
    let command = s.[i] in
    let position = i in
    if command == '[' then
      Stack.push bracestack position
    else if command == ']' then
      (* TODO not finished implmenting this part *)
      let start: Int.t option = Stack.pop bracestack in
      Hashtbl.change bracemap 
        (* bruh why does it have to be so safe? just break bruh *)
        (Option.value ~default:0 start)
        ~f:(fun (x: int option) -> 
          match x with 
            | Some x -> Some (x + 1)
            | None -> Some 0
          );
  done

let eval (s: String.t) =
  (* TODO not yet implemented *)
  let contents = cleanup(s) in
  let ptr = ref 0 in
  let cells = ref [0] in
  let bracemap = get_bracemap (contents) in
  while !ptr < String.length contents do
    let cmd = contents.[!ptr] in
    match cmd with
      | '>' -> ptr := !ptr + 1
      | '<' -> ptr := !ptr - 1
      | _ -> ()
  done

let () =
  let contents = In_channel.read_all (Caml.Sys.argv.(1)) in
  print_endline contents;
  let rem = " kkk ggg fff vvv [] + , ---- <<<<" in
  print_endline (cleanup rem)
