(*********************************************************************************)
(*  "Introduction au langage OCaml" par Maxence Guesdon est mis                  *)
(*  � disposition selon les termes de la licence Creative Commons                *)
(*   Paternit�                                                                   *)
(*   Pas d'Utilisation Commerciale                                               *)
(*   Partage des Conditions Initiales � l'Identique                              *)
(*   2.0 France.                                                                 *)
(*                                                                               *)
(*  Contact: Maxence.Guesdon@inria.fr                                            *)
(*                                                                               *)
(*                                                                               *)
(*********************************************************************************)

let dir_handle = Unix.opendir "/tmp";;

try

  while true do

    let f = Unix.readdir dir_handle in

    print_endline f

  done

with End_of_file -> Unix.closedir dir_handle;;
