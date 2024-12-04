{
	description = "minishell flake";
	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-24.11";
	};

	outputs = { self, nixpkgs, ... }:
	let
		supportedSystems = [ "x86_64-linux" ];
		forAllSystems = f: nixpkgs.lib.genAttrs supportedSystems (system: f {
			pkgs = import nixpkgs { inherit system; };
		});
	in
	{
		packages = forAllSystems ({ pkgs }: rec {
			default = minishell;
			minishell = pkgs.stdenv.mkDerivation {
				name = "minishell";
				src = self;
				buildInputs = with pkgs; [
					gcc clang readline
				];
				hardeningDisable = [ "all" ];
				buildPhase = ''
					make
				'';
				installPhase = ''
					mkdir -p $out/bin
					cp -r * $out/bin
				'';
			};
		});
	};
}
