let _ =
  let fd = Mylib1.myopen "foobarbaz" 0 in
  Printf.fprintf stderr "[OCaml] Got descriptor %d\n%!" fd;
  Mylib1.myclose fd
