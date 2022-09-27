mod actors_interface;
use actors_interface::*;
pub mod piezostack;
pub mod positionner;
pub mod tiptilt;

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn piezostack() {
        let _ = piezostack::Controller::new();
    }
    #[test]
    fn positionner() {
        let _ = positionner::Controller::new();
    }
    #[test]
    fn tiptilt() {
        let _ = tiptilt::Controller::new();
    }
}
