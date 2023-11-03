module golang.org/x/mobile

replace golang.org/x/mobile => /Users/subbotkin/projects/mobile

replace golang.org/x/mobile/bind => /Users/subbotkin/projects/mobile/bind

replace golang.org/x/mobile/bind/objc => /Users/subbotkin/projects/mobile/bind/objc

go 1.18

require (
	golang.org/x/exp/shiny v0.0.0-20230817173708-d852ddb80c63
	golang.org/x/image v0.12.0
	golang.org/x/mod v0.12.0
	golang.org/x/sync v0.3.0
	golang.org/x/tools v0.13.0
)

require golang.org/x/sys v0.12.0 // indirect
