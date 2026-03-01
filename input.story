story StudentResult
begins

character marks holds 85
character passMark holds 40

narrate marks

when marks > passMark
narrate marks
otherwise
narrate passMark

during marks > 0
marks holds marks - 10
narrate marks

end story
