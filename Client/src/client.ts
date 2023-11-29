import {ExtensionContext} from 'vscode';
import {Executable, LanguageClient, LanguageClientOptions, ServerOptions, TransportKind} from 'vscode-languageclient/node';

export function deactivate(_ : ExtensionContext)
{
    return undefined;
}

export function activate(context : ExtensionContext)
{
    const rd : Executable =
    {
        command: "iris",
        transport: TransportKind.stdio,
        args: ["stream"]
    };
    const so : ServerOptions =
    {
        debug: rd,
        run: rd
    };
    const lco : LanguageClientOptions =
    {
        documentSelector:
        [
            {
                scheme: "file",
                language: 'sclera'
            }
        ]
    };
    const lc : LanguageClient = new LanguageClient("iris", so, lco);
    context.subscriptions.push(lc);
    lc.start();
}