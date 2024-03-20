use std::mem;
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_in_between(list1: Option<Box<ListNode>>, a: i32, b: i32, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = list1.unwrap();
        let mut curr = head.as_mut();
        for _ in 0..(a - 1) {
            curr = curr.next.as_mut().unwrap();
        }
		
        mem::swap(&mut curr.next, &mut list2);
        
        while curr.next.is_some() {
            curr = curr.next.as_mut().unwrap();
        }

        for _ in 0..(b - a + 1) {
            list2 = list2.unwrap().next;
        }
        curr.next = list2;
        
        return Some(head);
    }
}